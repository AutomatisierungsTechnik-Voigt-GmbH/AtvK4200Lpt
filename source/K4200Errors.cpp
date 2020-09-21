/*
 * Copyright (C) 2020 Torsten Brischalle
 *
 * AutomatisierungsTechnik Voigt GmbH
 * Heilbronner Str. 17
 * 01189 Dresden
 * Germany
 *
 * web:   https://www.atv-systems.de
 * email: atv@atv-systems.de
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "K4200Errors.h"

namespace k4200
{
    /// <summary>
    /// Translates a K4200 error code to a human readable error message.
    /// </summary>
    /// <param name="errorCode">The error code to be translated.</param>
    /// <returns>The human readable error message.</returns>
    std::string K4200LptErrors::TranslateErrorCode(int errorCode)
    {
        switch (errorCode)
        {
        case 2802: return "RPM: Invalid Configuration Requested";
        case 2803: return "RPM: Invalid Configuration Requested";
        case 2804: return "RPM: Invalid Configuration Requested";
        case 2805: return "RPM: Invalid Configuration Requested";
        case 2806: return "RPM: Invalid Configuration Requested";
        case 2807: return "RPM: Invalid Configuration Requested";
        case 2801: return "RPM: Returned ID Error Response";
        case 2800: return "RPM: Command Response Timeout";
        case 2702: return "PMU: Temperature Within Normal Range";
        case 2701: return "PMU: High Temperature Limit Exceeded";
        case 1905: return "PMU: Measure Program Error";
        case 1904: return "PMU: Source Program Error";
        case 1902: return "PMU: Transmission to analog from digital error";
        case 1901: return "PMU: Handshake from analog to digital error";
        case 1900: return "PMU: DA Communication Timeout";
        case 400: return "PMU: Invalid Attributes in SW Command";
        case 401: return "PMU: Invalid Attributes in SW Command";
        case 402: return "PMU: Invalid Attributes in SW Command";
        case 100: return "LPTLib is executing function %s on instrument ID %d.";
        case 55: return "%s is no longer in thermal shutdown.";
        case 54: return "%s VXIBus device busy (command ID %04x). Timed out after %g seconds.";
        case 53: return "%s VXIbus transaction recovered after %u timeouts.Model 4200A-SCS Parameter Analyzer Reference Manual Section 13: LPT library function reference";
        case 52: return "%s VXIbus transaction (command ID %04x) timed out after %g seconds.";
        case 51: return "Interlock reset.";
        case 50: return "Interlock tripped.";
        case 40: return "%s";
        case 24: return "Config %d-%d complete for %s (%d).";
        case 23: return "Config %d-%d starting for %s (%d).";
        case 22: return "Binding %s (%d) to driver %s.";
        case 21: return "Loading driver %s.";
        case 20: return "Preloading model code %08x (%s).";
        case 15: return "Executor started.";
        case 14: return "%s channel closed.";
        case 13: return "%s channel starting.";
        case 12: return "TAPI services shutting down.";
        case 11: return "Starting TAPI services.";
        case 9: return "System configuration complete.";
        case 8: return "System configuration starting.";
        case 4: return "System initialization complete.";
        case 1: return "The call was successful (no error).";
        case 0: return "The call was successful (no error).";
        case -4: return "Too many instruments in configuration file %s.";
        case -5: return "Memory allocation failure.";
        case -6: return "Memory allocation error during configuration with configuration file %s.";
        case -20: return "Command not executed because a previous error was encountered.";
        case -21: return "Tester is in a fatal error state.";
        case -22: return "Fatal condition detected while in testing state.";
        case -23: return "Execution aborted by user.";
        case -24: return "Too many arguments.";
        case -25: return "%s is unavailable because it is in use by another test station.";
        case -40: return "%s.";
        case -87: return "Can not load library %s.";
        case -88: return "Invalid configuration file %s.";
        case -89: return "Duplicate IDs.";
        case -90: return "Duplicate instrument addresses in configuration file %s.";
        case -91: return "Duplicate instrument slots in configuration file %s.";
        case -93: return "Unrecognized/missing interface for %s in configuration file %s.";
        case -94: return "Unrecognized/missing PCI slot number for %s in configuration file %s.";
        case -95: return "Unrecognized/missing GPIB address for %s in configuration file %s.";
        case -96: return "GPIB Address out of range for %s was %i in configuration file %s.";
        case -97: return "PCI slot number out of range for %s was %i in configuration file %s.";
        case -98: return "Error attempting to load driver for model %s in configuration file %s.";
        case -99: return "Unrecognized/missing instrument ID in configuration file %s.";
        case -100: return "Invalid connection count, number of connections passed was %d.";
        case -101: return "Argument #%d is not a pin in the current configuration.";
        case -102: return "Multiple connections on %s.";
        case -103: return "Dangerous connection using %s.Section 13: LPT library function reference Model 4200A-SCS Parameter Analyzer Reference Manual";
        case -104: return "Unrecognized instrument or terminal not connected to matrix, argument #%d.";
        case -105: return "No pathway assigned to argument #%d.";
        case -106: return "Path %d previously allocated.";
        case -107: return "Not enough pathways to complete connection.";
        case -108: return "Argument #%d is not defined by configuration.";
        case -109: return "Illegal test station: %d.";
        case -110: return "A ground connection MUST be made.";
        case -111: return "Instrument low connection MUST be made.";
        case -113: return "There are no switching instruments in the system configuration.";
        case -114: return "Illegal connection.";
        case -115: return "Operation not allowed on a connected pin: %d.";
        case -116: return "No physical bias path from %s to %s.";
        case -117: return "Connection cannot be made because a required bus is in use.";
        case -118: return "Cannot switch to high current mode while sources are active.";
        case -119: return "Pin %d in use.";
        case -120: return "Illegal connection between %s and GNDU.";
        case -121: return "Too many calls were made to trigXX.";
        case -122: return "Illegal value for parameter #%d.";
        case -124: return "Sweep/Scan measure table overflow.";
        case -126: return "Insufficient user RAM for dynamic allocation.";
        case -129: return "Timer not enabled.";
        case -137: return "Invalid value for modifier.";
        case -138: return "Too many points specified in array.";
        case -139: return "An error was encountered while accessing the file %s.";
        case -140: return "%s unavailable while slaved to %s.";
        case -141: return "Timestamp not available because no measurement was made.";
        case -142: return "Cannot bind, instruments are incompatible.";
        case -143: return "Cannot bind, services unavailable or in use.";
        case -152: return "Function not supported by %s (%d).";
        case -153: return "Instrument with ID %d is not in the current configuration.";
        case -154: return "Unknown instrument name %s.";
        case -155: return "Unknown instrument ID %i.";
        case -158: return "VXI device in slot %d failed selftest (mfr ID: %04x, model number: %04x).";
        case -159: return "VME device with logical address %d is either non-VXI or non-functional.";
        case -160: return "Measurement cannot be performed because the source is not operational.";
        case -161: return "Instrument in slot %d has non-functional dual-port RAM.";
        case -164: return "VXI device in slot %d statically addressed at reserved address %d.";
        case -165: return "Service not supported by %s (%d).";
        case -166: return "Instrument with model code %08x is not recognized.";
        case -167: return "Invalid instrument attribute %s.";
        case -169: return "Instrument %s is not in the current configuration.";
        case -190: return "Ill-formed connection.";
        case -191: return "Mode conflict.";
        case -192: return "Instrument sense connection MUST be made.";
        case -200: return "Force value too big for highest range %g.Model 4200A-SCS Parameter Analyzer Reference Manual Section 13: LPT library function reference";
        case -202: return "I-limit value %g too small for specified range.";
        case -203: return "I-limit value %g too large for specified range.";
        case -204: return "I-range value %g too large for specified range.";
        case -206: return "V-limit value %g too large for specified range.";
        case -207: return "V-range value %g too large for specified range.";
        case -213: return "Value too big for range selection, %g.";
        case -218: return "Safe operating area for device exceeded.";
        case -221: return "Thermal shutdown has occurred on device %s.";
        case -224: return "Limit value %g too large for specified range.";
        case -230: return "V-limit value %g too small for specified range.";
        case -231: return "Range too small for force value.";
        case -233: return "Cannot force when not connected.";
        case -235: return "C-range value %g too large for specified range.";
        case -236: return "G-range value %g too large for specified range.";
        case -237: return "No bias source.";
        case -238: return "VMTR not allocated to make the measurement.";
        case -239: return "Timeout occurred attempting measurement.";
        case -240: return "Power Limited to 20 W. Check voltage and current range settings.";
        case -250: return "IEEE-488 time out during data transfer for addr %d.";
        case -252: return "No IEEE-488 interface in configuration.";
        case -253: return "IEEE-488 secondary address %d invalid for device.";
        case -254: return "IEEE-488 invalid primary address: %d.";
        case -255: return "IEEE-488 receive buffer overflow for address %d.";
        case -261: return "No SMU found, kelvin connection test not performed.";
        case -262: return "SRU not responding.";
        case -263: return "DMM not connected to SRU.";
        case -264: return "GPIB communication problem.";
        case -265: return "SRU not mechanically calibrated.";
        case -266: return "Invalid SRU command.";
        case -267: return "SRU hardware problem.";
        case -268: return "SRU kelvin connection problem.";
        case -269: return "SRU general error.";
        case -270: return "Floating point divide by zero.";
        case -271: return "Floating point log of zero or negative number.";
        case -272: return "Floating point square root of negative number.";
        case -273: return "Floating point pwr of negative number.";
        case -280: return "Label #%d not defined.";
        case -281: return "Label #%d redefined.";
        case -282: return "Invalid label ID #%d.";
        case -301: return "PCI ID read back on send error, slot.";
        case -455: return "Protocol version mismatch.";
        case -510: return "No command byte available (read) or SRQ not asserted.";
        case -511: return "CAC conflict.";
        case -512: return "Not CAC.";
        case -513: return "Not SAC.Section 13: LPT library function reference Model 4200A-SCS Parameter Analyzer Reference Manual";
        case -514: return "IFC abort.";
        case -515: return "GPIB timed out.";
        case -516: return "Invalid function number.";
        case -517: return "TCT timeout.";
        case -518: return "No listeners on bus.";
        case -519: return "Driver problem.";
        case -520: return "Bad slot number.";
        case -521: return "No listen address.";
        case -522: return "No talk address.";
        case -523: return "IBUP Software configuration error.";
        case -524: return "No utility function.";
        case -550: return "EEPROM checksum error in %s: %s.";
        case -551: return "EEPROM read error in %s: %s.";
        case -552: return "EEPROM write error in %s: %s.";
        case -553: return "%s returned unexpected error code %d.";
        case -601: return "System software internal error; contact the factory.";
        case -602: return "Module load error: %s.";
        case -603: return "Module format error: %s.";
        case -604: return "Module not found: %s.";
        case -610: return "Could not start %s.";
        case -611: return "Network error.";
        case -612: return "Protocol error.";
        case -620: return "Driver load error. Could not load %s.";
        case -621: return "Driver configuration function not found. Driver is %s.";
        case -640: return "%s serial number %s failed diagnostic test %d.";
        case -641: return "%s serial number %s failed diagnostic test %d with a fatal fault.";
        case -650: return "Request to open unknown channel type %08x.";
        case -660: return "Invalid group ID %d.";
        case -661: return "Invalid test ID %d.";
        case -662: return "Ill-formed list.";
        case -663: return "Executor is busy.";
        case -664: return "Invalid unit ID %d.";
        case -701: return "Error configuring serial port %s.";
        case -702: return "Error opening serial port %s.";
        case -703: return "Call kspcfg before using kspsnd or ksprcv.";
        case -704: return "Error reading serial port.";
        case -705: return "Timeout reading serial port.";
        case -706: return "Terminator not received before read buffer filled.";
        case -707: return "Error closing serial port %s.";
        case -801: return "Exception code %d reported from VPU in slot %d, channel %d.";
        case -802: return "VPU in slot %d has reached thermal limit.";
        case -803: return "Start and stop values for defined segmented arb violate minimum slew rate.";
        case -804: return "Function not valid in the present pulse mode.";
        case -805: return "Too many points specified in array.";
        case -806: return "Not enough points specified in array.Model 4200A-SCS Parameter Analyzer Reference Manual Section 13: LPT library function reference";
        case -807: return "Function not supported by 4200-VPU.";
        case -808: return "Solid state relay control values ignored for 4200-VPU.";
        case -809: return "Time Per Point must be between %g and %g.";
        case -810: return "Attempts to control VPU trigger output are ignored by the 4200-VPU.";
        case -811: return "Measure range not valid for %s.";
        case -812: return "WARNING: Sequence %d, segment %d. Cannot measure with PGUs/VPUs.";
        case -820: return "PMU segment start value %gV at index %d does not match previous segment stop value of %gV.";
        case -821: return "PMU segment stop time (%g) greater than segment duration (%g)";
        case -822: return "PMU sequence error for entry %d. Start value %gV does not match previous stop value of %gV.";
        case -823: return "Start and stop window was specified for PMU segment %d, but no measurement type was set.";
        case -824: return "Measurement type was specified for PMU segment %d, but start and stop window is invalid.";
        case -825: return "%s set to post to column %s. Cannot fetch data that was registered as real-time.";
        case -826: return "Cannot execute PMU test. No channels defined.";
        case -827: return "Invalid pulse timing parameters in PMU Pulse IV test.";
        case -828: return "Maximum number of segments per PMU channel exceeded (%d).";
        case -829: return "The sum of base and amplitude voltages (%gV) exceeds maximum (%gV) for present range.";
        case -830: return "Pulse waveform configuration exceeded output limits. Increase pulse period or reduce amplitude or total time of pulsing.";
        case -831: return "Maximum number of samples per channel (%d) exceeded for PMU%d-CH%d.";
        case -832: return "Pulse slew rate is too low. Increase pulse amplitude or reduce pulse rise and fall time.";
        case -833: return "Invalid trigger source for PIV test.";
        case -834: return "Invalid pulse timing parameters.";
        case -835: return "Using the specified sample rate of %g samples/s, the time (%g) for sequence %d is too short for a measurement.";
        case -836: return "WARNING: Sequence %d, segment %d is attempting to measure while solid state relay is open. Disabling measurement.";
        case -837: return "No RPM connected to channel %d of PMU in slot %d.";
        case -838: return "Timing parameters specify a pulse that is too short for a measurement using %g samples/s.";
        case -839: return "Timing parameters contain measurement segments that are too short to measure using %g samples/s.";
        case -840: return "SSR cannot be opened when using RPM ranges. Please change SSR array to enable relay or select PMU measure range.";
        case -841: return "WARNING: SSR is open on segment immediately preceding sequence %d. Measurement will be invalid for 25 µs while relay settles.";
        case -842: return "This test has exceeded the system power limit by %g watts.";
        case -843: return "Step size of %g is not evenly divisible by 10 ns.";
        case -844: return "Invalid combination of start %g1, stop %g2 and step %g3.";
        case -845: return "No pulse sweeper was configured - Test will not run.";
        case -846: return "Maximum Source Voltage Reached: Requested voltage across DUT resistance exceeds maximum voltage available.";
        case -847: return "Output was not configured - Test will not run.";
        case -848: return "Sweep step count mismatch for the sweeping channels. All sweeping channels must have same # of steps.Section 13: LPT library function reference Model 4200A-SCS Parameter Analyzer Reference Manual";
        case -849: return "ILimit command is not supported for RPM in slot %d, channel %d.";
        case -850: return "Sample Rate mismatch. All channels in test must have the sample rate.";
        case -851: return "Invalid PxU stepper/sweeper configuration.";
        case -900: return "Environment variable KI_PRB_CONFIG is not set. The prober drivers will be inaccessible.";
        case -901: return "Environment variable KI_PRB_CONFIG contains an invalid path. The prober drivers will be inaccessible.";
        case -902: return "Prober configuration file not found. File was %s. The prober drivers will be inaccessible.";
        case -903: return "Unable to copy the prober configuration %s to %s. The prober driver many not be available.";
        default:
            return "";
        }
    }

} // namespace k4200

